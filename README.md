# Exercícios de Programação em C

Este repositório contém exercícios práticos de programação em C, organizados por listas de exercícios.

## Aluno

**Nome:** Ruy Monteiro

## Estrutura do Repositório

O repositório está organizado da seguinte forma:

### Estrutura Original

```
L1/
  ├── ex1/
  │   ├── main.c
  │   └── [outros arquivos]
  ├── ex2/
  │   ├── main.c
  │   └── [outros arquivos]
  └── ...
L2/
  ├── ex1/
  │   ├── main.c
  │   └── [outros arquivos]
  └── ...
```

### Estrutura Após Organização

```
L1/
  ├── ex1.c
  ├── ex2.c
  └── ...
L2/
  ├── ex1.c
  └── ...
```

## Script de Organização

Este repositório inclui um script Python para organizar automaticamente os exercícios, movendo os arquivos `main.c` para o diretório principal de cada lista e renomeando-os adequadamente.

### Como Usar o Script

1. Certifique-se de ter Python instalado em seu sistema
2. Navegue até o diretório raiz do repositório
3. Execute o script:
   ```bash
   python organize.py
   ```

### Funcionalidades do Script

- Opção de organizar todas as listas ou uma lista específica
- Verificação automática de diretórios que precisam de organização
- Feedback em português sobre as operações realizadas
- Contagem de exercícios organizados
- Tratamento de erros e interrupções

### Exemplo de Uso

1. Ao executar o script, você verá as opções disponíveis:

   ```
   Listas disponíveis: L1, L2, L3...
   ```

Opções:

1. Organizar todas as listas
2. Organizar uma lista específica
3. Remover arquivos .exe de todas as listas
4. Remover arquivos .exe de uma lista específica

```

2. Escolha a opção desejada e siga as instruções na tela
3. O script informará sobre cada arquivo movido e diretório removido
4. Ao final, será exibido um resumo das operações realizadas
```
