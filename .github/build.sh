mkdir prod
cd prod
git clone https://github.com/Daynlight/CPP-Data
git checkout Lib
cd ..

git submodule update --remote
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd ..

cp build/Release/CPP-DATA.lib prod/CPP-DATA.lib
cp CPP-DATA/Data.h prod/Data.h
cp LICENSE prod/LICENSE

rm -r build/