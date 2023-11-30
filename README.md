# Agenda-de-Bienestar-

El bienestar es una parte fundamental para la felicidad y el sentido de plenitud de las personas. Para conseguir este bienestar es importante tener un balance en las distintas dimensiones que conforman a una persona. Hay muchas maneras en las que se han clasificado estas dimensiones, pero en este caso tendremos en cuenta la dimensión física, social, personal y vocacional.

En primer lugar, la dimensión física involucra toda actividad que beneficie a tu salud, como lo es el ejercicio, una dieta balanceada y dormir adecuadamente. Por otro lado, la dimensión social engloba toda interacción que se tenga con otras personas, ya que como personas tenemos la necesidad de relacionarnos y compartir tiempo con los demás. En la dimensión personal se puede considerar que se alimenta con ejercicios de autoconocimiento, trabajar en el área espiritual (creencias), recreación o practicar un hobbie, etc. Por último, las actividades enfocadas en tus pasiones, tu profesión, conseguir nuevos conocimientos y trabajar en la parte financiera es lo que se toma en cuenta en la dimensión vocacional. A partir de estas cuatro dimensiones, cada una de ellas desarrolla una parte importante en el crecimiento como persona, por lo que es importante cuidar de cada una de ellas para mantener un balance en tu vida.

A raíz de esta situación, este proyecto busca llevar un registro del usuario para cada una de estas dimensiones y que pueda visualizar el enfoque que está llevando en su vida y así pueda decidir qué cambios debería de hacer. Para esto, el proyecto se trata de una agenda la cuál añades eventos o actividades en los días del mes, definiendo que tipo de dimensión se está trabajando durante esta actividad. Al llevar un registro de las dimensiones que se trabajan en la vida diaria, el usuario podrá ver qué dimensiones está descuidando y podría tener un enfoque más amplio debido a la conciencia de lo que está trabajando como persona.

![UMLProyecto drawio (1)](https://github.com/EdgarRetes/Agenda-de-Bienestar-/assets/113946434/a54ad96f-568d-4c58-b4c2-83fa0f39bca5)

Así es como se verían las clases del programa, donde la clase principal es el mes que está compuesto por un vector de días. En cada uno de esos días se pueden agregar objetos de las clases herencia eventos, ya sea un evento personal, físico, vocacional y social. Para esto se usan distintos métodos como añadir eventos, borrar eventos y mostrar eventos, los cuales añaden los objetos a sus valores correspondientes y a través de métodos auxiliares, se pueden mostrar los cambios hechos por el usuario en su calendario, desplegando toda la información con los métodos displayCalendar y displayDay, así el usuario puede ver en su terminal los eventos agendados en el mes de manera fácil, al igual que el modo de modificarlo.

Para poder correr el código debes seguir los siguientes pasos:
1. Installar visual studio code: https://code.visualstudio.com/docs/setup/windows
2. Instalar las extensión de c++ y un compilador: https://code.visualstudio.com/docs/languages/cpp
3. Descargar el archivo zip del repositorio, extraer los archivos y cargarlos en la ventana de archivos en VS Code.
4. Abrir una nueva terminal (Ctrl+Shift+Ñ).
5. Crear el archivo .exe con el comando g++ Agenda.cpp -o Agenda
6. Correr el archivo .exe con este comando ./Agenda.exe
