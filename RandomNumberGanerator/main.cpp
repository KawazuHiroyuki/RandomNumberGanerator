// main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "RandomNumberGenerator.h"

int main()
{
    //random_number_generator::RandomNumberGenerator<unsigned int> random;

    using namespace random_number_generator;
    using Type = unsigned int;

    auto seed0 = SeedGeneratorFactory::create(SeedGeneratorParameter<Type>{ SeedGeneratorID::StdRandomDevice });
    auto seed1 = SeedGeneratorFactory::create(SeedGeneratorParameter<Type>{ SeedGeneratorID::CurrentTime });
    auto seed2 = SeedGeneratorFactory::create(SeedGeneratorParameter<Type>{ SeedGeneratorID::Custom, []() { return 10;  } });

    std::cout << (*seed0)() << "\n";
    std::cout << (*seed1)() << "\n";
    std::cout << (*seed2)() << "\n";
    
#if 0
    StdRandomDeviceSeedGenerator<Type>();

    StdLiearCongruentialRandomNumberEngine<Type, Type, 1, 1, 0>(std::make_shared<RandomNumberEngineParameter<Type, Type>>(), std::make_shared<SeedGenerator<Type>>());
    StdMersenneTwisterRandomNumberEngine<Type, Type, 32, 624, 397, 31,
        0x9908b0df, 11, 0xffffffff, 7,
        0x9d2c5680, 15, 0xefc60000, 18, 1812433253>(std::make_shared<RandomNumberEngineParameter<Type, Type>>(), std::make_shared<SeedGenerator<Type>>());
    StdSubtractWithCarryRandomNumberEngine<Type, Type, 24, 10, 24>(std::make_shared<RandomNumberEngineParameter<Type, Type>>(), std::make_shared<SeedGenerator<Type>>());

    //StdDefaultRandomEngine<Type, Type>(std::shared_ptr<SeedGenerator<Type>>(new SeedGenerator<Type>()));
    auto a = StdDefaultRandomEngine<Type, Type>(std::make_shared<SeedGenerator<Type>>());
    StdKnuthRandomNumberEngine<Type, Type>(std::make_shared<RandomNumberEngineParameter<Type, Type>>(), std::make_shared<SeedGenerator<Type>>());
    StdMinStdRand0RandomNumberEngine<Type, Type>(std::make_shared<RandomNumberEngineParameter<Type, Type>>(), std::make_shared<SeedGenerator<Type>>());
    StdMinStdRandRandomNumberEngine<Type, Type>(std::make_shared<RandomNumberEngineParameter<Type, Type>>(), std::make_shared<SeedGenerator<Type>>());
    StdMt199937_32BitRandomNumberEngine<Type, Type>(std::make_shared<RandomNumberEngineParameter<Type, Type>>(), std::make_shared<SeedGenerator<Type>>());
    StdRandomDevice<Type, Type>(std::make_shared<RandomNumberEngineParameter<Type, Type>>(), std::make_shared<SeedGenerator<Type>>());
    StdRanlux24RandomNumberEngine<Type, Type>(std::make_shared<RandomNumberEngineParameter<Type, Type>>(), std::make_shared<SeedGenerator<Type>>());

    using Type2 = unsigned long long;
    StdMt199937_64BitRandomNumberEngine<Type2, Type2>(std::make_shared<RandomNumberEngineParameter<Type2, Type2>>(), std::make_shared<SeedGenerator<Type2>>());
    StdRanlux48RandomNumberEngine<Type2, Type2>(std::make_shared<RandomNumberEngineParameter<Type2, Type2>>(), std::make_shared<SeedGenerator<Type2>>());
#endif

    std::cout << "Hello World!\n";
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
