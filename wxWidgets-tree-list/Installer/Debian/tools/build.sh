rm wxhello-world_0.90.0_amd64.deb
rm -rf wxhello-world_0.90.0_amd64

mkdir wxhello-world_0.90.0_amd64
mkdir wxhello-world_0.90.0_amd64/DEBIAN
mkdir wxhello-world_0.90.0_amd64/usr
mkdir wxhello-world_0.90.0_amd64/usr/bin

cp control wxhello-world_0.90.0_amd64/DEBIAN/control
cp ../../build-linux-release/main wxhello-world_0.90.0_amd64/usr/bin/wxhelloworld
strip wxhello-world_0.90.0_amd64/usr/bin/wxhelloworld

dpkg --build wxhello-world_0.90.0_amd64
