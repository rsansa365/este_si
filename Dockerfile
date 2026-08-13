FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV G4_VERSION=11.2.0

# 1. Instalar librerías de sistema y entorno gráfico (Qt/OpenGL)
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    wget \
    ca-certificates \
    libxerces-c-dev \
    libexpat1-dev \
    libqt5opengl5-dev \
    qtbase5-dev \
    libxmu-dev \
    libxi-dev \
    nano \
    && rm -rf /var/lib/apt/lists/*

# 2. Descargar y compilar Geant4
WORKDIR /tmp
RUN wget https://gitlab.cern.ch/geant4/geant4/-/archive/v${G4_VERSION}/geant4-v${G4_VERSION}.tar.gz \
    && tar -xzf geant4-v${G4_VERSION}.tar.gz \
    && mkdir geant4-build && cd geant4-build \
    && cmake -DGEANT4_INSTALL_DATA=ON \
             -DGEANT4_USE_QT=ON \
             -DGEANT4_USE_OPENGL_X11=ON \
             -DGEANT4_BUILD_MULTITHREADED=ON \
             -DCMAKE_INSTALL_PREFIX=/opt/geant4 \
             ../geant4-v${G4_VERSION} \
    && make -j4 \
    && make install \
    && rm -rf /tmp/*

# 3. Copiar el contenido local a la imagen
RUN mkdir -p /geant4lab/proyecto_lluvias_cosmico
COPY proyecto_lluvias_cosmico/ /geant4lab/proyecto_lluvias_cosmico/

# 4. Crear el script geant4make.sh global
ENV QT_QPA_PLATFORM=offscreen

RUN echo '#!/bin/bash\nsource /opt/geant4/bin/geant4.sh' > /usr/local/bin/geant4make.sh \
    && chmod +x /usr/local/bin/geant4make.sh

# Cargar automáticamente el entorno en bash
RUN echo "source /usr/local/bin/geant4make.sh" >> /etc/bash.bashrc

WORKDIR /geant4lab/proyecto_lluvias_cosmico

CMD ["/bin/bash"]
