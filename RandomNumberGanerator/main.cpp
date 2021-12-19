// main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>

#include "RandomNumberGenerator.h"

int main()
{
    using namespace random_number_generator;

    using Seed = unsigned int;
    std::vector<std::shared_ptr<SeedEngine<Seed>>> seeds = {
        SeedEngineFactory::create(SeedEngineParameter<Seed>{ SeedEngineID::StdRandomDevice }),
        SeedEngineFactory::create(SeedEngineParameter<Seed>{ SeedEngineID::CurrentTime }),
        SeedEngineFactory::create(SeedEngineParameter<Seed>{ SeedEngineID::Custom, []() { return 10;  } })
    };
    std::cout << "--- Seed ---" << std::endl;
    for (auto seed : seeds) {
        std::cout << (*seed)() << std::endl;
    }

    using Type = std::uint32_t;

    std::vector<RandomNumberGenerator<unsigned int>> engines = {
        RandomNumberGenerator<unsigned int>(RandomNumberEngineID::StdRandomDevice, {SeedEngineID::StdRandomDevice}),
        RandomNumberGenerator<unsigned int>(RandomNumberEngineID::StdMinStdRand0, {SeedEngineID::CurrentTime}),
        RandomNumberGenerator<unsigned int>(RandomNumberEngineID::StdMinStdRand, {SeedEngineID::Custom, []() { return static_cast<std::uint64_t>(10); }}),
        RandomNumberGenerator<unsigned int>(RandomNumberEngineID::StdMt199937_32Bit),
        RandomNumberGenerator<unsigned int>(RandomNumberEngineID::StdMt199937_64Bit),
        RandomNumberGenerator<unsigned int>(RandomNumberEngineID::StdRanlux24),
        RandomNumberGenerator<unsigned int>(RandomNumberEngineID::StdRanlux48),
        RandomNumberGenerator<unsigned int>(RandomNumberEngineID::StdKnuth),
        RandomNumberGenerator<unsigned int>(RandomNumberEngineID::StdDefaultRandomEngine)
    };

    std::cout << "--- Random ---" << std::endl;
    for (auto& engine : engines) {
        std::cout << engine() << std::endl;
        engine.discard(0);
    }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
