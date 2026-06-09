# Fangs & Fists

> Jogo de luta 2D estilo fliperama com integração Arduino e acessibilidade cognitiva — desenvolvido em mBlock 5

<div align="center">

![mBlock](https://img.shields.io/badge/mBlock-5.6.0-blue?style=for-the-badge)
![Arduino](https://img.shields.io/badge/Arduino-Uno-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow?style=for-the-badge)
![License](https://img.shields.io/badge/Licença-MIT-green?style=for-the-badge)

</div>

---

## 📖 Sobre o Projeto

**Fangs & Fists** é um jogo de luta 2D desenvolvido em mBlock (baseado em Scratch) com integração física via Arduino Uno. O projeto foi criado como trabalho universitário em equipe, com foco especial em **acessibilidade cognitiva** — projetado para ser jogável por pessoas com TDAH e autismo nível 1.

Os jogadores escolhem personagens com atributos únicos, utilizam poderes especiais e disputam rodadas em combate direto, com controles físicos via botões conectados ao Arduino.

---

## ✨ Funcionalidades

- 🎮 **Dois modos de jogo:** Multiplayer local e Singleplayer (vs. bot)
- 🦁 **4 personagens jogáveis**, cada um com stats únicos de Força e Velocidade
- ⚡ **4 poderes especiais** com cooldown e uso único por batalha
- 🕹️ **Controles físicos** via 4 botões conectados ao Arduino Uno
- 📊 **Sistema de HP com barra visual** animada em tempo real
- 🔄 **Rodadas configuráveis** (1, 3 ou 5 por partida)
- ♿ **Design acessível** para jogadores com diferenças cognitivas

---

## 🦁 Personagens

| Personagem | Força | Velocidade | Estilo |
|------------|-------|------------|--------|
| Leão       | Alto  | Médio      | Tanque |
| Tigre      | Médio | Alto       | Ágil   |
| Tubarão    | Muito Alto | Baixo | Brutal |
| Gorila     | Alto  | Baixo      | Poderoso |

> **Fórmula de dano:** `dano = Força × 0.055`
> **Velocidade de ataque:** `espera = 1 ÷ (Velocidade × 0.6)`

---

## ⚡ Poderes Especiais

| Poder     | Efeito                                      | Cooldown | Observações                    |
|-----------|---------------------------------------------|----------|-------------------------------|
| 🧊 Gelo   | Paralisa o oponente por 3 segundos          | 5s       | Uso único por batalha          |
| 🛡️ Escudo | Bloqueia todo dano recebido por 5 segundos  | —        | Uso único por batalha          |
| ☠️ Veneno | Drena -5 HP/seg durante 4 segundos          | —        | Uso único por batalha          |
| 🦷 Mordida| Dano instantâneo de -30 HP                  | —        | Bloqueável pelo Escudo         |

---

## 🏗️ Arquitetura do Projeto

```
fangs-and-fists/
├── game/
│   ├── fangs_and_fists.mblock     # Projeto principal mBlock
│   └── sprites/                   # Assets dos personagens
├── arduino/
│   └── buttons_reader.ino         # Código de leitura dos botões
├── docs/
│   └── apresentacao.pptx          # Apresentação universitária
└── README.md
```

### Fluxo de Jogo

```
Menu Principal
    └── Seleção de Modo (Multi / Single)
            └── Seleção de Rodadas (1 / 3 / 5)
                    └── Seleção de Personagem (J1 → J2)
                            └── Combate
                                    └── Tela de Resultado
```

---

## 🔧 Hardware

### Componentes Necessários

- 1× Arduino Uno
- 4× Botões (push buttons)
- Cabos jumper
- Protoboard

### Mapeamento de Pinos

| Botão         | Pino Arduino | Jogador |
|---------------|--------------|---------|
| Azul          | 5            | J1      |
| Amarelo       | 2            | J1      | 
| Verde         | 4            | J2      |
| Vermelho      | 7            | J2      |

### Esquema de Conexão

```
Botão → Pino Digital → Arduino → Arduino IDE → Python → mBlock
```

> Os pinos são lidos com `INPUT_PULLUP`. Cada leitura é enviada ao mBlock via broadcasts para comunicação com os sprites do jogo.

---

## 💻 Variáveis Principais

| Variável              | Descrição                              |
|-----------------------|----------------------------------------|
| `vida_j1` / `vida_j2` | HP de cada personagem           |
| `estado`              | Estado atual do jogo                   |
| `modo_jogo`           | Multiplayer ou Singleplayer            |
| `personagem_j1/j2`    | Personagem escolhido por cada jogador  |
| `poder_j1/j2`         | Poder especial equipado                |
| `cooldown_j1/j2`      | Temporizador de cooldown do poder      |
| `rodada_atual`        | Rodada em andamento                    |
| `total_rodadas`       | Total de rodadas da partida            |
| `tempo_partida`       | Cronômetro da rodada                   |
| `game_iniciado`       | Flag de controle de início de partida  |

---

## 🚀 Como Executar

### Pré-requisitos

- [mBlock 5.6.0](https://mblock.makeblock.com/) (desktop)
- [Arduino IDE](https://www.arduino.cc/en/software) (para upload do código dos botões)
- Arduino Uno + cabos USB

### Passo a Passo

1. **Clone o repositório**
   ```bash
   git clone https://github.com/seu-usuario/fangs-and-fists.git
   cd fangs-and-fists
   ```

2. **Configure o Arduino**
   - Abra `arduino/buttons_reader.ino` na Arduino IDE
   - Conecte o Arduino Uno via USB
   - Faça o upload do sketch

3. **Abra o projeto no mBlock**
   - Abra o mBlock 5
   - Carregue o arquivo `game/fangs_and_fists.mblock`
   - Conecte ao Arduino via mBlock (aba "Dispositivos")

4. **Jogue!**
   - Clique na bandeira verde para iniciar
   - Use os botões físicos para atacar e usar poderes

> **Sem Arduino?** O jogo também pode ser jogado pelo teclado em modo de simulação. O botão azul é a tecla H

---

## 🗺️ Roadmap

- [x] Sistema de HP e barras de vida
- [x] 4 personagens com stats únicos
- [x] 4 poderes especiais com cooldown
- [x] Integração com Arduino (botões físicos)
- [x] Animações de ataque, dano e morte
- [x] Modos de rodadas (1/3/5)
- [ ] Bot para modo Singleplayer
- [ ] Sistema de dificuldade adaptativa
- [ ] Integração NFC (cartões RC522 para seleção de personagem)

---

> Projeto desenvolvido para disciplina universitária Projetos 1 da CESAR School 🏆

---

## ♿ Acessibilidade Cognitiva

O Fangs & Fists foi projetado com atenção às necessidades de jogadores com dificuldades de atenção e processamento:

- Interface visual clara com feedbacks imediatos
- Animações distintas para cada ação de jogo
- Controles físicos que reduzem carga cognitiva de teclado
- Tempo de cooldown visível para planejamento de ações
- Estrutura de rodadas curtas para manter o foco
- Sistema adaptativo de diminuição de velocidade

---

## 📄 Licença

Distribuído sob a licença MIT. Veja `LICENSE` para mais informações.

---

## 👥 Equipe

| Membro     | Responsabilidade                          |
|------------|-------------------------------------------|
| Letícia    |  |
| [Membros]   |       |

<div align="center">
  Feito com ❤️ e muito <code>broadcast</code>
</div>
