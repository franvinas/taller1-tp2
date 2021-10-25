# Trabajo Práctico 2

Materia: Taller de Programación I (75.42)

Alumno: Francisco Viñas

Padrón: 103207

Link al repositorio: https://github.com/franvinas/taller1-tp2


## Introducción

El tabajo práctico consiste en tomar un dataset que no puede entrar en memoria, partirlo en múltiples sub-datasets más chicos que sí pueden entrar en memoria, operar sobre cada uno de ellos y combinar los resultados parciales para obtener un resultado final. Las operaciones posibles son: `sum`, `mean`, `min` y `max`. Cada operación se realiza sobre los elementos de una única columna entre las filas `start_range` y `end_range`.

## Descripción de clases

### Dataset

Inicialmente el programa recibe el nombre de un archivo binario con números de 2 bytes sin signo, en big endian y sin padding. La clase `Dataset` se ocupa de abrir este archivo y encapsular su lógica. Para leer una determinada partición se debe usar la función `read_partition`. De esta forma, no se carga todo el archivo en memoria sino únicamente las filas indicadas por el usuario de la función `read_partition`.

### Operation

La clase `Operation` es una clase abstracta. De esta heredan: `Sum`, `Mean`, `Min` y `Max`. Todas estas clases hijas tienen unicamente un constructor, una función `apply` y una función `read_partition`. De esta forma se puede usar cualquiera de las clases hijas de forma polimórfica.

### Partition

Como se explicó en la descripción de `Dataset`, no se cargan todos los datos del dataset en memoria al mismo tiempo sino que se cargan particiones del mismo. La clase `Partition` es una abstracción de una particion en memoria. Esta almacena los datos de la partición e información importante como la cantidad de filas y columnas de la partición y la columna sobre la que se realizan las operaciones. Además, tiene un atributo entero `current_row` que se utiliza como indice para iterar sobre todas las filas de la partición. Las funciones `next()` y `end()` sirven para iterar sobre la partición. La primera devuelve el valor que se encuentra en la siguiente fila sobre la columna correspondiente y la segunda función devuelve un booleano indicando si la iteración llegó al final de la partición.

### PartitionMetadata

Esta clase permite encapsular la información de una partición. Se utiliza para que cuando se requiere mover esta información se haga pasando un único objeto y no tres variables distintas.

### Task

Por entrada estandar se reciben tareas a realizar, la clase `Task` es una abstracción de una tarea. Cada tarea cuenta con una operación a realizar sobre ciertas filas del dataset. El método de mayor complejidad es `apply()` donde se toma una nueva partición y se itera sobre la misma aplicando la operación (polimorficamente) sobre cada fila en la columna correspondiente. Los otros métodos de la clase delegan a las clases `TaskAttributes` y `Operation`.

### TaskAttributes

`TaskAttributes` permite quitarle ciertas responsabilidades a `Task` y encapsularlas en otra clase. Esta clase contiene la metadata de la tarea, es decir, la fila inicial, final y la columna sobre las cuales realizar la operación. Además hay un atributo `current_row` que sirve para saber cual es la próxima partición sobre la cual operar. Por último, están los atributos `total_partitions` y `partitions_done`. El primero indica el total de particiones sobre las cuales hay que operar y el segundo indica la cantidad de particiones sobre las cuales ya se operó.

### TaskQueue

Esta clase lee de la entrada estandar la información sobre las tareas a realizar. Con esta información crea instancias de tipo `Task` y las guarda en una cola. Con el método `front()` se obtiene una referencia al primer `Task` que tenga particiones sobre las cuales todavía no se haya operado. Con el método `empty()` se puede consultar si ya fueron completadas todas las tareas.

### Thread

**Autoría:** El autor de esta clase es la cátedra Veiga de la materia Taller de Programación I (7542/9508) de la Facultad de Ingeniería de la UBA.

Esta es una clase abstracta. Toda clase que herede de `Thread` debe implementar el método protegido `run()`. La interfaz de esta clase consta con las funciones `start()` y `join()`. La primera de estas funciones lanza un hilo que corre la función `run()`. Por otro lado, la segunda de estas funciones, espera a que termine la ejecución del hilo.

### Worker

Esta clase hereda de `Thread`. La clase `Worker` implementa la función `run()`. Esta función lo único que hace es pedir por la siguiente tarea y llamar al método `apply` de la clase `Task`. Esto se hace dentro de un ciclo mientras que no se hayan completado todas las tareas. Notar que el método `apply` opera sobre una única partición y luego retorna, entonces por cada iteración dentro del ciclo se opera sobre una sola partición. Esto permite que haya varios hilos trabajando sobre una única tarea pero en particiones diferentes. Cada instancia de `Worker` tiene una referencia a la cola de tareas (`TaskQueue`) y al dataset (`Dataset`); es necesario que sean referencias porque todas las instancias de `Worker` deben poder acceder a estos objetos.
