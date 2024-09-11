#include <Siv3D.hpp> // Siv3D v0.6.14
#include "SivSUSAnalyzer.hpp"

#define CATCH_CONFIG_RUNNER
#include <ThirdParty/Catch2/catch.hpp>

void Main() {
    s3d::Console.open();

    Catch::Session session;
    session.useConfigData({
        .waitForKeypress = Catch::WaitForKeypress::BeforeExit
    });

    session.run();
}
