declare -a files=(`ls -d -1 ./**/*.cpp`)

echo "🟢 Running: g++ ./main.cpp ${files[*]} -o ./main && ./main"

`g++ $PWD/main.cpp ${files[*]} -o $PWD/main && $PWD/main`

if [ "$1" = "--geomview" ]; then
  if [ "$2" != "" ]; then
    echo "📁 Opening file \"./off_files/$2.off\" in geomview."
    `geomview $PWD/off_files/$2.off`
  else
    echo "🔴 [Error] Flag --geomeview needs to be passed then the name of the file to be opened."
  fi
fi