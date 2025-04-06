# Decriptyx

Jogo de decodificação de padrões pseudoaleatórios. O *Decriptyx* é um projeto de jogo que foi desenvolvido a partir de um livro chamado *"C++ de A à Z"*. Comecei a desenvolvê-lo quando estava estudando a linguagem C++, contudo fui indo para outras fontes e deixando de lado o livro que por ser muito antigo eu achei que não fosse o melhor lugar para estudar o C++ moderno. O jogo em questão aparenta não estar em lugar algum da internet, nem mesmo o executável, nem mesmo o código fonte, então pela nostalgia e por eu querer que isto esteja disponível na web tanto para fins educacionais quanto para fins históricos transformarei este repositório num museu.

###### Requisitos para compilação

1. C++98
2. G++ Compiler
3. Makefile
	
## Configurações de ambiente

Para este projeto estou utilizando o Visual Studio Code com algumas configurações especiais no diretório ``.vscode``, não é obrigatório então apenas faça se souber o que está fazendo. As configurações são as que seguem:

1. c_cpp_properties.json

```json

{
    "configurations": [
        {
            "name": "Linux",  // Ou "Win32" se for Windows
            "includePath": [
                "${workspaceFolder}/include",  // Seus headers locais
                "/usr/include"                // Headers do sistema
            ],
            "defines": [
                "DEBUG"                      // Define DEBUG se necessário
            ],
            "compilerPath": "/usr/bin/g++",  // Caminho do compilador
            "cStandard": "c99",              // Padrão C (opcional)
            "cppStandard": "c++98",           // Padrão C++98
            "intelliSenseMode": "linux-gcc-x64",  // Modo de IntelliSense
            "configurationProvider": "ms-vscode.makefile-tools"  // Se usar extensão Makefile Tools
        }
    ],
    "version": 4
}
```

2. launch.json

```json

{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug C++",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/bin/debug",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Habilitar pretty-printing para gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "build-debug",
            "miDebuggerPath": "/usr/bin/gdb"
        }
    ]
}
```

3. tasks.json


```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build-debug",
            "type": "shell",
            "command": "make debug",
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": []
        },
        {
            "label": "build-release",
            "type": "shell",
            "command": "make release",
            "problemMatcher": []
        }
    ]
}
```

