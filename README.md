# Proyecto 2 "Administración de Usuarios"

Este proyecto esta trabajado con la versión **C++ 17**. Se utilizo para apoyo visual el uso de la librería **["CppConsoleTable"](https://github.com/DenisSamilton/CppConsoleTable)** , esta librería es utilizada para crear una especie de tabla en la consola para hacer mas atractiva la presentación del contenido (no agrega nada de apoyo lógico).

![enter image description here](https://i.ibb.co/wgpy8H3/image.png)

# Modelo Alumno
Este es el modelo de la estructura que se usara a lo largo del proyecto.
![enter image description here](https://i.ibb.co/sVwnQrx/struct.png)

# Funcionamiento

Al iniciar el proyecto podrá encontrarse con la posibilidad de realizar 4 posibles acciones, que son las siguientes:

 1. Agregar Alumno
 2. Buscar Alumnos
 3. Listar Alumnos
 4. Modificar Alumno

![enter image description here](https://i.ibb.co/y68cnVs/image.png)

Para ingresar a cualquiera de las opciones debe ingresar el numero de la accion que se desea realizar. Ejemplo, 1 seria si deseamos "Agregar Alumno".
## Agregar Alumno

Si ingresamos la opción "1", nos desplegara paso a paso cada uno de los datos que son necesarios para crear al alumno (Fueron definidos en la sección Modelo Alumno). En el caso del Estado, solo esta permitido ingresar el carácter "A" (Aprobado) o "R" (Reprobado) de lo contrario, no permitirá ingresar hasta que sea una de esas opciones.
![enter image description here](https://i.ibb.co/3Y8fqx2/image.png)

Luego de enviar todos los datos necesario podremos visualizar los datos ya almacenados mas el dato que se ingreso.
![enter image description here](https://i.ibb.co/MpmWsfK/image.png)


## Buscar Alumnos

Si ingresamos la opción "2", nos desplegara porque campo de los datos del Alumno se desea buscar, como se muestra a continuación:
![enter image description here](https://i.ibb.co/0XvQ0W3/image.png)

Dependiendo el parámetro que se desee buscar, se realizara la búsqueda. Si hubiera casualmente 2 o más alumnos con el mismo valor en el parámetro buscado, se mostraran ambos.

![enter image description here](https://i.ibb.co/tQ4KZGw/image.png)

## Listar Alumnos

Si ingresamos la opción "3", nos listara todos los datos ingresados con todos sus parámetros dentro del documento binario.

![enter image description here](https://i.ibb.co/28sVJfH/image.png)

## Modificar Alumno

Si ingresamos la opción "4", nos pedirá ingresar un numero de Id del alumno que deseamos buscar:
![enter image description here](https://i.ibb.co/mFJrPwd/image.png)

Luego de eso debemos ingresar el Id del Alumno a modificar y nos mostrara los datos del Alumno al cual modificaremos y debemos escoger que deseamos modificar de ese Alumno:
![enter image description here](https://i.ibb.co/kBgSjsd/image.png)

Seleccionamos que modificaremos e ingresamos el nuevo dato y nos desplegara el dato ya modificado:
![enter image description here](https://i.ibb.co/0rQVMwz/image.png)



