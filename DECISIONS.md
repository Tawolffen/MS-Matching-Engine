# Decisões Técnicas

Este documento registra as decisões de design tomadas durante a implementação e a justificativa por trás de cada uma. Deve ser atualizado incrementalmente, junto com os commits que implementam cada decisão — não escrito tudo de uma vez ao final.

## Representação de preço

**Decisão:** preço é armazenado internamente como inteiro escalado (`Price = int64_t`, 4 casas decimais, `domain/price.hpp`), não como `double`.

**Justificativa:** o book usa preço como chave de um `std::map` e faz comparações de igualdade/ordenação constantemente (ex: decidir se uma limit order cruza, encontrar o best bid/offer). Ponto flutuante binário não representa exatamente valores decimais como `10.1`, o que pode causar comparações incorretas ou duplicação de níveis de preço que deveriam ser o mesmo. Um inteiro escalado tem aritmética e comparação exatas.

## Estrutura de dados do book

**Decisão:** `std::map<Price, std::deque<Order>>`, um para bids e um para asks.

**Justificativa:** `std::map` mantém os preços ordenados automaticamente (O(log n) para inserir/acessar um nível de preço), o que dá acesso direto ao melhor preço via `begin()`/`rbegin()` — operação muito frequente (toda ordem market e toda peg order consulta isso). Dentro de cada nível de preço, um `std::deque` preserva a ordem de chegada (FIFO): `push_back` ao inserir, `pop_front` ao preencher, conforme o requisito adicional 2.

*(pendente de implementação)* Cancelamento/alteração por `OrderId` isolado, sem saber previamente o preço da ordem, exige um índice auxiliar (`unordered_map<OrderId, ...>`) para não degradar para O(n). Ver TODO em `order_book.hpp`.

## Limit orders que cruzariam ao entrar

**Decisão:** _(a preencher — o enunciado exige explicitamente justificar esta escolha)._

Duas opções válidas:
- **Preencher (comportamento de exchange real):** uma limit buy a 20 quando já existe uma limit sell a 20 no book gera um trade imediatamente, e só o restante (se houver) vira ordem passiva. É o comportamento mais realista e é o que os exemplos do enunciado parecem sugerir implicitamente.
- **Ignorar/rejeitar:** a ordem é sempre inserida como passiva, mesmo que cruzasse — simplifica a implementação mas não reflete uma matching engine real.

Registrar aqui qual foi escolhida e por quê antes de implementar `Matcher::submit`.

## Ordens Market sem liquidez suficiente

**Decisão:** _(a preencher)._ O que acontece com uma market order maior que a quantidade total disponível no lado oposto do book? Preencher parcialmente e descartar o restante, ou rejeitar a ordem inteira? Os exemplos do enunciado (`market buy 200` após o book só ter 150 disponível a 20) sugerem preenchimento parcial.

## Identificador de ordens

**Decisão:** `OrderId` é um inteiro incremental (`uint64_t`), atribuído pelo `Matcher` ao inserir a ordem.

**Justificativa:** o enunciado usa `identificador_1` apenas como exemplo textual do formato de saída; um contador simples é suficiente, thread-safety não é requisito (engine single-threaded, premissa 3/4 do enunciado).

## Ordens Peg

**Decisão:** _(a preencher)._ Pontos a decidir e justificar:
- Quando reavaliar o preço de uma peg order: só ao inserir, ou continuamente a cada mudança do best bid/offer (o exemplo do enunciado mostra reavaliação contínua)?
- Uma peg order participa da fila FIFO no preço atual como qualquer limit order, perdendo posição sempre que seu preço de referência muda (mesma regra do requisito adicional 4)?
