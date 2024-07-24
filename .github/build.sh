mkdir prodLib
cd prodLib
git clone -b Lib https://github.com/Daynlight/CPP-Data .
cd ..

git submodule update --remote
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd ..

cp build/Release/CPP-DATA.lib prodLib/Data.lib
cp CPP-DATA/Data.h prodLib/Data.h
cp LICENSE prodLib/LICENSE

rm -r build/

mkdir prodRelease
cd prodRelease
git clone -b Release https://github.com/Daynlight/CPP-Data .
git submodule add -b Lib https://github.com/Daynlight/SQLite SQLite
cd ..

cp -r CPP-DATA/* prodRelease/
cp LICENSE prodRelease/LICENSE

cd prodLib
git add .
git commit -am "Update Lib from build.sh"
cd ..

cd prodRelease
git add .
git commit -am "Update Release from build.sh"
cd ..