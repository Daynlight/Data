result=${PWD##*/}
result=${result:-/}

if [ "$result" == ".github" ]; then
    cd ..
fi

git clean -xfd
rm -rf build/
rm -rf prodLib/
rm -rf prodRelease/

if [ "$result" == ".github" ]; then
    cd .github
fi