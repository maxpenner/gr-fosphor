gr-fosphor - gnuradio block for RTSA-like spectrum visualization
================================================================

[Original README.md of parent project](https://github.com/osmocom/gr-fosphor/blob/master/README.md)

## Installation

Tested on:
- Ubuntu 24.04.1 LTS
- Linux 6.8.0-52-generic
- GNU Radio 3.10.9.2 (Python 3.12.3)
- UHD_4.6.0.0
- Intel x86 i9-10980XE
- Nvidia 2070 Super
- USRP N321

[UHD incl. GNU Radio](https://files.ettus.com/manual/page_install.html)

```console
sudo apt-get install libuhd-dev uhd-host
```

[QT](https://askubuntu.com/questions/1404263/how-do-you-install-qt-on-ubuntu22-04)

```console
sudo apt install qtbase5-dev
```

[GLFW3 Dependencies](https://www.glfw.org/docs/latest/compile_guide.html)

```console
sudo apt install libwayland-dev libxkbcommon-dev xorg-dev
```

[GLFW3](https://osmocom.org/projects/sdr/wiki/fosphor#GLFW3)

```console
sudo apt-get install xorg-dev libglu1-mesa-dev
```
```console
git clone https://github.com/glfw/glfw
cd glfw
mkdir build
cd build
cmake ../ -DBUILD_SHARED_LIBS=true
make
sudo make install
sudo ldconfig
```
[Nvidia OpenCL](https://osmocom.org/projects/sdr/wiki/fosphor#NVidia-OpenCL)

```console
sudo apt-get install nvidia-opencl-dev opencl-headers
```

Under "Additional Drivers", switch from nouveau to Nvidia driver, for instance nvidia-driver-550.

[gr-fosphor](https://osmocom.org/projects/sdr/wiki/fosphor#gr-fosphor-2)

```console
sudo apt-get install gnuradio-dev opencl-headers libboost-system-dev libboost-thread-dev
```
```console
git clone https://gitea.osmocom.org/sdr/gr-fosphor.git
cd gr-fosphor
mkdir build
cd build
cmake ..
make
sudo make install
sudo ldconfig
```

## GNU Radio Examples

Most basic flow graph can be found in examples/.