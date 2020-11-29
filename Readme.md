# ControlSimCore

## 概要
- C++による制御システムシミュレータ
- シミュレーション結果はCSVデータ

## 言語
- C++17

## 環境
Windows 10 or macOS
1. Visual Studio 2019 (Communityで動作確認済み)
1. CMake
1. ターミナル

## CMakeによる実行方法
```
mkdir build
cd build
cmake ..
make clean all
./main
```

## ターミナルからの実行方法
```
g++ -Wall -std=c++17 main.cpp -o main
./main
```

## 構成
- main.cpp: 制御システムや制御則を記述
- solver/: 微分方程式を数値計算するライブラリ
- csv/: CSVファイルの書き込みを行うライブラリ