// main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include "RandomNumberGenerator.h"
#include "private/RandomNumberEngineUtility.h"

int main()
{
    //random_number_generator::RandomNumberGenerator<unsigned int> random;

    using namespace random_number_generator;

    //std::uniform_int_distribution<>;

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
    auto engine0 = EngineFactory<StdRandomDevice>::create();
    auto ptrEngine0 = std::dynamic_pointer_cast<StdRandomDevice>(engine0);

    auto engine1 = EngineFactory<StdMinStdRand0RandomNumberEngine>::create();
    auto ptrEngine1 = std::dynamic_pointer_cast<StdMinStdRand0RandomNumberEngine>(engine1);

    auto engine2 = EngineFactory<StdMinStdRandRandomNumberEngine>::create();
    auto ptrEngine2 = std::dynamic_pointer_cast<StdMinStdRandRandomNumberEngine>(engine2);

    auto engine3 = EngineFactory<StdMt199937_32BitRandomNumberEngine>::create();
    auto ptrEngine3 = std::dynamic_pointer_cast<StdMt199937_32BitRandomNumberEngine>(engine3);

    auto engine4 = EngineFactory<StdMt199937_64BitRandomNumberEngine>::create();
    auto ptrEngine4 = std::dynamic_pointer_cast<StdMt199937_64BitRandomNumberEngine>(engine4);

    auto engine5 = EngineFactory<StdRanlux24RandomNumberEngine>::create();
    auto ptrEngine5 = std::dynamic_pointer_cast<StdRanlux24RandomNumberEngine>(engine5);

    auto engine6 = EngineFactory<StdRanlux48RandomNumberEngine>::create();
    auto ptrEngine6 = std::dynamic_pointer_cast<StdRanlux48RandomNumberEngine>(engine6);

    auto engine7 = EngineFactory<StdKnuthRandomNumberEngine>::create();
    auto ptrEngine7 = std::dynamic_pointer_cast<StdKnuthRandomNumberEngine>(engine7);

    auto engine8 = EngineFactory<StdDefaultRandomEngine>::create();
    std::shared_ptr<StdDefaultRandomEngine> ptrEngine8 = std::dynamic_pointer_cast<StdDefaultRandomEngine>(engine8);

    std::cout << "--- Random ---" << std::endl;
    std::cout << "StdRandomDevice : " << (*ptrEngine0)() << std::endl;
    std::cout << "StdMinStdRand0RandomNumberEngine : " << (*ptrEngine1)() << std::endl;
    std::cout << "StdMinStdRandRandomNumberEngine : " << (*ptrEngine2)() << std::endl;
    std::cout << "StdMt199937_32BitRandomNumberEngine : " << (*ptrEngine3)() << std::endl;
    std::cout << "StdMt199937_64BitRandomNumberEngine : " << (*ptrEngine4)() << std::endl;
    std::cout << "StdRanlux24RandomNumberEngine : " << (*ptrEngine5)() << std::endl;
    std::cout << "StdRanlux48RandomNumberEngine : " << (*ptrEngine6)() << std::endl;
    std::cout << "StdKnuthRandomNumberEngine : " << (*ptrEngine7)() << std::endl;
    std::cout << "StdDefaultRandomEngine : " << (*ptrEngine8)() << std::endl;
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
