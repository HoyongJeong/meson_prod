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
I suppose you already have `GEANT4` installed on your computer. And `CERN ROOT` is required to see the result file.

### Build
```sh
git clone https://github.com/HoyongJeong/meson_prod
cd meson_prod
mkdir build
cd build
cmake ../source
make -j
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE -->
## Usage

### Execution
Basically, `./meson_prod -h` shows you the help message.

### Example Output files
In `source/example_outputs`, there are two `.root` files.
`ftfp_bert_1M.root` file is an output where the reference physics list is FTFP_BERT and the number of protons on target is 1M.
`qgsp_bert_1M.root` file has the same condition, except that the QGSP_BERT physics list is used.

<p align="right">(<a href="#readme-top">back to top</a>)</p>
