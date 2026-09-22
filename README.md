# Matching Engine

Implementação de uma matching engine simples (1 ativo, ordens limit/market/peg) em C++17, com um REPL de linha de comando.

## Requisitos

- CMake >= 3.16
- Um compilador C++17 (MSVC / Visual Studio Build Tools no Windows, ou MinGW-w64)
- Acesso à internet na primeira configuração (o CMake baixa o Catch2 automaticamente para os testes)

## Como compilar e rodar

```bash
cmake -S . -B build
cmake --build build
./build/matching_engine       # (no Windows: build\Debug\matching_engine.exe ou similar, dependendo do gerador)
```

## Como rodar os testes

```bash
cmake --build build --target unit_tests
ctest --test-dir build --output-on-failure
```

## Exemplo de uso do REPL

```
>>> limit buy 10 100
>>> limit sell 20 100
>>> limit sell 20 200
>>> market buy 150
Trade, price: 20, qty: 150
```

## Estrutura do projeto

```
src/
├── main.cpp            # entrypoint, inicia o REPL
├── domain/              # Order, Trade, enums, representação de preço
├── engine/               # OrderBook (estruturas de dados do livro) e Matcher (regras de cruzamento)
└── cli/                  # parser de comandos e loop do REPL
tests/                    # testes unitários (Catch2), um arquivo por área
```

## Decisões técnicas

Ver [DECISIONS.md](./DECISIONS.md) para as justificativas de cada escolha (representação de preço, comportamento de limit orders que cruzariam, estrutura de dados do book, etc.).
