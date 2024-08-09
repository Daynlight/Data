result=${PWD##*/}
result=${result:-/}

if [ "$result" == ".github" ]; then
    cd ..
fi

mkdir prodLib
git submodule update --remote
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd ..

cp build/Release/Data.lib prodLib/Data.lib
cp Data/*.h prodLib/*.h
cp LICENSE prodLib/LICENSE

rm -r build/

mkdir prodRelease
cp -r Data/* prodRelease/
cp LICENSE prodRelease/LICENSE

if [ "$result" == ".github" ]; then
    cd .github
fi