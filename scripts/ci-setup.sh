#!/bin/sh

sudo apt update -y
sudo apt install -y build-essential libconfig-dev libgtk-3-dev libayatana-appindicator3-dev cmake python3 gcovr

python3 -m pip install meson ninja
