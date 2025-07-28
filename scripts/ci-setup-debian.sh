#!/bin/sh

apt update -y
apt upgrade -y
apt install -y meson libayatana-appindicator3-dev pkg-config bison flex gcovr
