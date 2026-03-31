# 🧩 Jogo dos 15

Um jogo dos 15 (15-puzzle) feito em linguagem C, jogado diretamente no terminal. O objetivo é reorganizar os números de 1 a 15 em ordem crescente movendo as peças com o teclado.

---

## 📋 Sobre o Projeto

O Jogo dos 15 é um quebra-cabeça clássico em que você move peças numeradas em um tabuleiro 4x4 até deixá-las em ordem. Este projeto implementa o jogo inteiramente no terminal, com três níveis de dificuldade, contador de movimentos e cronômetro.

```
  1   2   3   4 
  5   6   7   8 
  9  10  11  12 
 13  14  15    
```

---

## 🎮 Como Jogar

Use as teclas **WASD** para mover as peças:

| Tecla | Movimento |
|-------|-----------|
| `W`   | Move a peça de baixo para cima (empurra o espaço vazio para baixo) |
| `S`   | Move a peça de cima para baixo (empurra o espaço vazio para cima) |
| `A`   | Move a peça da direita para esquerda (empurra o espaço vazio para a direita) |
| `D`   | Move a peça da esquerda para direita (empurra o espaço vazio para a esquerda) |

O jogo termina quando todos os números estiverem em ordem crescente, com o espaço vazio no canto inferior direito.

---

## ⚙️ Níveis de Dificuldade

| Nível | Peças fora do lugar (mínimo) |
|-------|-------------------------------|
| 1 - Fácil   | 5  |
| 2 - Médio   | 9  |
| 3 - Difícil | 13 |

---

## 📊 Estatísticas ao Final da Partida

Ao vencer, o jogo exibe:
- ✅ Total de movimentos realizados
- ⏱️ Tempo de resolução em segundos

---

## 🛠️ Execução

### Pré-requisitos

- GCC (GNU Compiler Collection)
- Sistema operacional Linux ou macOS (usa `system("clear")` e `unistd.h`)

```bash
./jogo15
```

---

## 📁 Estrutura do Código

| Função | Descrição |
|--------|-----------|
| `main()` | Loop principal do jogo, controla o fluxo de partidas |
| `menu()` | Exibe o menu inicial e captura a dificuldade escolhida |
| `printMat()` | Renderiza o tabuleiro 4x4 no terminal |
| `switchTile()` | Processa a entrada do usuário e realiza a troca de peças |
| `scramble()` | Executa um único movimento aleatório para embaralhar |
| `dificultyScramble()` | Embaralha o tabuleiro conforme o nível de dificuldade escolhido |
| `win()` | Verifica se o tabuleiro está na configuração vencedora |

