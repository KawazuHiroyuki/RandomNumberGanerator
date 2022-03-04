// main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <string> 
#include <iostream>
#include <vector>

#include "RandomNumberGenerator/RandomNumberGenerator.h"

int main()
{
    using namespace random_number_generator;

    using Seed = unsigned int;
    std::vector<std::shared_ptr<AbstractSeedEngine<Seed>>> seeds = {
        SeedEngineFactory::create(SeedEngineParameter<Seed>{ SeedEngineID::StdRandomDevice }),
        SeedEngineFactory::create(SeedEngineParameter<Seed>{ SeedEngineID::CurrentTime }),
        SeedEngineFactory::create(SeedEngineParameter<Seed>{ SeedEngineID::Custom, []() { return 10;  } })
    };
    std::cout << "--- Seed ---" << std::endl;
    for (auto seed : seeds) {
        std::cout << (*seed)() << std::endl;
    }

    using Type = std::uint64_t;

    std::cout << "--- True Random Number ---" << std::endl;

    auto printTrueRandomNumberEngine = [](const std::string& brief, auto engine) {
        std::cout << "--- " << brief << " ---" << std::endl;
        std::cout << "Min :" << engine->getMin() << std::endl;
        std::cout << "Max :" << engine->getMax() << std::endl;
        std::cout << "Engropy :" << engine->getEntropy() << std::endl;
        std::cout << "Gene1 :" << engine->operator()() << std::endl;
    };

    std::shared_ptr<StdRandomDevice> a0 = EngineFactory<StdRandomDevice>::create(RandomNumberEngineID::StdRandomDevice);
    printTrueRandomNumberEngine("StdRandomDevice", a0);

    std::cout << "--- Pseudo Random Number ---" << std::endl;

    auto printPseudoRandomNumberEngine = [](const std::string& brief, auto engine) {
        std::cout << "--- " << brief << " ---" << std::endl;
        std::cout << "Min :" << engine->getMin() << std::endl;
        std::cout << "Max :" << engine->getMax() << std::endl;
        std::cout << "Engropy :" << engine->getEntropy() << std::endl;
        std::cout << "Gene1 :" << (*engine).operator()() << std::endl;
        engine->discard(0);
        std::cout << "Gene2 :" << engine->operator()() << std::endl;
    };

    using Seed1 = std::uint_fast32_t;
    std::shared_ptr<StdMinStdRand0RandomNumberEngine<Seed1>> a1 = EngineFactory<StdMinStdRand0RandomNumberEngine<Seed1>, Seed1>::create(RandomNumberEngineID::StdMinStdRand0, { SeedEngineID::CurrentTime });
    printPseudoRandomNumberEngine("StdMinStdRand0RandomNumberEngine", a1);

    std::shared_ptr<StdMinStdRandRandomNumberEngine<Seed1>> a2 = EngineFactory<StdMinStdRandRandomNumberEngine<Seed1>, Seed1>::create(RandomNumberEngineID::StdMinStdRand, { SeedEngineID::Custom, []() { return static_cast<std::uint_fast32_t>(10); } });
    printPseudoRandomNumberEngine("StdMinStdRandRandomNumberEngine", a2);

    std::shared_ptr<StdMt199937_32BitRandomNumberEngine<Seed1>> a3 = EngineFactory<StdMt199937_32BitRandomNumberEngine<Seed1>, Seed1>::create(RandomNumberEngineID::StdMt199937_32Bit);
    printPseudoRandomNumberEngine("StdMt199937_32BitRandomNumberEngine", a3);

    using Seed2 = std::uint_fast64_t;
    std::shared_ptr<StdMt199937_64BitRandomNumberEngine<Seed2>> a4 = EngineFactory<StdMt199937_64BitRandomNumberEngine<Seed2>, Seed2>::create(RandomNumberEngineID::StdMt199937_64Bit);
    printPseudoRandomNumberEngine("StdMt199937_64BitRandomNumberEngine", a4);

    std::shared_ptr<StdRanlux24RandomNumberEngine<Seed1>> a5 = EngineFactory<StdRanlux24RandomNumberEngine<Seed1>, Seed1>::create(RandomNumberEngineID::StdRanlux24);
    printPseudoRandomNumberEngine("StdRanlux24RandomNumberEngine", a5);

    std::shared_ptr<StdRanlux48RandomNumberEngine<Seed2>> a6 = EngineFactory<StdRanlux48RandomNumberEngine<Seed2>, Seed2>::create(RandomNumberEngineID::StdRanlux48);
    printPseudoRandomNumberEngine("StdRanlux48RandomNumberEngine", a6);

    std::shared_ptr<StdKnuthRandomNumberEngine<Seed1>> a7 = EngineFactory<StdKnuthRandomNumberEngine<Seed1>, Seed1>::create(RandomNumberEngineID::StdKnuth);
    printPseudoRandomNumberEngine("StdKnuthRandomNumberEngine", a7);

    std::shared_ptr<StdDefaultRandomEngine<Seed1>> a8 = EngineFactory<StdDefaultRandomEngine<Seed1>, Seed1>::create(RandomNumberEngineID::StdDefaultRandomEngine);
    printPseudoRandomNumberEngine("StdDefaultRandomEngine", a8);

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
