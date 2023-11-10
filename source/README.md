<a name="readme-top"></a>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/HoyongJeong/meson_prod">
    <img src="https://github.com/othneildrew/Best-README-Template/blob/master/images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">meson_prod</h3>

  <p align="center">
    Meson Production by Proton Beam on Graphite Target
    <br />
    <a href="https://github.com/othneildrew/Best-README-Template"><strong>Explore the docs »</strong></a>
    <br />
  </p>
</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#installation">Installation</a>
    </li>
    <li><a href="#usage">Usage</a></li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About The Project

This `GEANT4` simulation counts mesons produced when an 800 MeV proton beam hits a graphite target.
The development was inspired by millicharged particles experiment at LANL.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- INSTALLATION -->
## Installation

### Prerequisites
I suppose you already have `GEANT4` installed on your computer. And CERN ROOT is required to see the result file.

### Build
```sh
git clone https://github.com/HoyongJeong/meson_prod
cd meson_prod
mkdir build
cd build
cmake ../source
make -j
```


<!-- USAGE -->
## Usage
Basically, `./meson_prod -h` shows you the help message.
