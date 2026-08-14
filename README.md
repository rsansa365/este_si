# Proyecto: Simulación de Lluvia Atmosférica (Geant4)

Este repositorio tiene el código fuente, la configuración para ejecutar la simulación, que esta usando el famoso **Geant4** y siguiendo estos pasos podrás sin problema ver la simulación realizada por este estudiante. 

## Requisitos mínimos en tu terminal 

Debes de tener instalado en tu terminal el Docker ya que es necesario para descargar la imagen que pondré mas adelante.


## Instalación y ejecución

### 1. Descarga la imagen de Docker 

La imagen ya tiene todo lo necesario para que funcione el entorno Geant4 como su código integrado, lo único que tiene hacer hacer es descargar la imagen.

```bash
docker pull ricard0o/estasi
```
Si has seguido la indicación hasta aquí e intentaste ejecutar la imagen, veras que se ejecuta pero no sale lo mas importante que es la terminal grafica, eso pasa porque para que Geant4 pueda abrir las ventanas de visualización (Qt/OpenGL) desde adentro del contenedor, debes permitir que Docker se conecte al servidor de pantalla de tu máquina local y eso se logra con este simple comando:

```bash
xhost +local:docker
```

### 2. Ejecutar el contenedor

Bueno ahora tendrás que copiar esta linea de código para poder ejecutar correctamente el código:

```bash
docker run -it --name simulacion --net=host --env="DISPLAY=$DISPLAY" --env="QT_QPA_PLATFORM=xcb" --env="LIBGL_ALWAYS_SOFTWARE=1" -v /tmp/.X11-unix:/tmp/.X11-unix:rw ricard0o/estasi:latest
```
Este comando ahora que entres automáticamente al contenedor y solo te queda navegar por las carpetas de este para llegar a la carpeta llamada build, en la cual esta el ejecutable de la simulación.
```bash
cd /geant4lab/proyecto_lluvias_cosmicas/build
```

Compilación del proyecto:
```bash
cmake ..
make -j4
```

Y ejecútalo:

```bash
./sim
```
### Felicidades has podido ejecutar con éxito la simulación, espero y te haya  gustado :)
