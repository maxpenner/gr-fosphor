gr-fosphor - gnuradio block for RTSA-like spectrum visualization
================================================================

This repository contains a GNU Radio block for RTSA-like spectrum visualization using OpenCL and OpenGL acceleration.

The block has been used successfully on Linux, OSX and Windows.

Homepage + Documentation
------------------------

For installation and usage guidelines please read the documentation available at <https://osmocom.org/projects/sdr/wiki/Fosphor>

Forum
-----

We welcome any fosphor related discussions in the [SDR](https://discourse.osmocom.org/c/sdr/) section of the osmocom discourse (web based Forum).

Mailing List
------------

Discussions related to libosmocore are happening on the osmocom-sdr@lists.osmocom.org mailing list, please see <https://lists.osmocom.org/mailman/listinfo/osmocom-sdr> for subscription options and the list archive.

Please observe the [Osmocom Mailing List Rules](https://osmocom.org/projects/cellular-infrastructure/wiki/Mailing_List_Rules) when posting.

Issue tracker
-------------

We are using the Osmocom redmine at <https://osmocom.org/projects/sdr/issues>

Contributing
------------

We maintain our source code in a self-hosted instance of gitea at <https://gitea.osmocom.org/sdr/gr-fosphor.git>. You can send pull requests there, or send patches the old-fashioned way (`git send-email`) to the above-mentioned mailing list.

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