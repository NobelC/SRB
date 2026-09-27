# SRB

SRB, por sus siglas en español (SISTEMA DE RECOLECCIÓN DE BASURA), es un pequeño
servicio atómico creado para encargarse de la limpieza de los archivos del
sistema.

Este es un servicio flojo, por llamarlo de algún modo más divertido. Cada X
tiempo (definido en días) hace su "Día de limpieza", en donde sigue las órdenes
establecidas por el usuario para borrar archivos. Cabe decir que, una vez
borrados, no hay forma de recuperarlos, me aseguraré de eso (será divertido si
algún desarrollador, luego de que SRB llegue a su fase final, demuestre que aún
puede recuperar sus archivos).

SRB deberá ser capaz de seguir reglas complejas de borrado, no quedarse en el
simple "Borra los archivos de X carpeta cada X tiempo", que también podría,
pero sería muy aburrido programar eso.

## Tipos de reglas y funcionalidades

- **Borrado de archivos en carpetas:** su función principal que no tiene gracia
  mencionar, SRB permite borrar los archivos de cualquier tipo de las carpetas
  seleccionadas.
- **Borrado por característica:** para englobar todas, y hacerlas formar parte
  de las reglas de funcionalidad, SRB permite borrar archivos por sus
  características (tamaño, extensión, tipo de archivo, permisos, tiempo de
  creación o modificación).

Me extendería más en las reglas que tengo planeadas, pero hasta no formar parte
de la realidad del código lo mantendré en esto. Iré documentando cómo usar SRB a
medida que lo voy creando, por ahora mi meta es lograr estas dos cosas.

## Creación de las reglas

Actualmente, para crear las reglas se usará un archivo JSON:

```json
{
  "home/usuario/downloads":{
    "extension" : ["cpp","json","png"],
  }
}
```

Este sencillo ejemplo establece que en la carpeta downloads, los archivos que tengan
extension cpp, json o png seran borrados, por defecto si el archivo tiene mas de
una regla y interpretara que se borrada todo aquello que cumpla alguna de las
condiciones, ejemplo:

```json
{
  "home/usuario/downloads":{
    "extension" : ["cpp","json","png"],
    "after-time": 5,
  }
}
```

En este ejemplo, primero se borarran los archivos que cumplan con la extension
y luego  los archivos que cumplan que su tiempo de creacion es mayor a 5 dias.
Se me olvidaba, el borrado es realizado en cascada, las reglas se aplican de
arriba hacia abajo, siguiendo el orden estricto de escritura.

Aunque actualmente no existe, pero es una idea que deseo implementar,
es que  SRB tendra un operador de logica AND, que permitira que se
requira cumplir  con todas las condiciones para ser eliminado, ejemplo:

```json
{
  "home/usuario/downloads":{
    "and":{
      "extension":["cpp","jpg"],
      "after-time":5,
    }
  }
}
```

Esto permite ahora que para borrar cualquier archivo en la carpeta
downloads se requiere que el archivo cumpla con tener la extension
y ademas cumplir que su tiempo de creacion sea mayor a 5 dias.

Escribire un ejemplo mas luego, que es solo para decir que pueden establecer
mas reglas para cada carpeta, pueden establecer reglas para que en la carpeta
pictures solo se borren los jpg, para que en descargar solo aquellas que
lleven mas de 4 de haberse creado, para que en documento se borre lo que lleve
mas de 10 dias sin abrise, etc, las posibilidades por ahora son limitadas.
