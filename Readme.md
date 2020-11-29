# ControlSimCore V1.0

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

## Visual Studio 2019での注意点
git clone時に以下の設定が引き継がれないので設定が必要になります
- C++標準言語：ISO C++17 標準（プロパティページ -> C/C++ -> 言語 -> ISO C++17 標準）

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