#include <Siv3D.hpp> // Siv3D v0.6.14
#include "SivSUSAnalyzer.hpp"
#include "SivSUSAnalyzer/Metadata.hpp"

#define CATCH_CONFIG_RUNNER
#include <ThirdParty/Catch2/catch.hpp>

void Main() {
    s3d::Console.open();

    s3d::TextReader reader(U"examples/test.sus");

    if (not reader) {
        throw s3d::Error(U"Failed to open `test.sus`");
    }

    s3d::String contents = reader.readAll();
    SivSUSAnalyzer::Metadata metadata = SivSUSAnalyzer::ParseMetadata(contents);

    s3d::Console << U"title = " << metadata.title;
    s3d::Console << U"subtitle = " << metadata.subtitle;
    s3d::Console << U"artist = " << metadata.artist;
    s3d::Console << U"genre = " << metadata.genre;
    s3d::Console << U"designer = " << metadata.designer;
    s3d::Console << U"difficulty = " << metadata.difficulty;
    s3d::Console << U"playLevel = " << metadata.playLevel;
    s3d::Console << U"songID = " << metadata.songID;
    s3d::Console << U"wave = " << metadata.wave;
    s3d::Console << U"waveOffset = " << metadata.waveOffset;
    s3d::Console << U"jacket = " << metadata.jacket;
    s3d::Console << U"background = " << metadata.background;
    s3d::Console << U"movie = " << metadata.movie;
    s3d::Console << U"movieOffset = " << metadata.movieOffset;
    s3d::Console << U"baseBPM = " << metadata.baseBPM;
    s3d::Console << U"requests = "  << metadata.requests;

    Catch::Session session;
    session.useConfigData({
        .waitForKeypress = Catch::WaitForKeypress::BeforeExit
    });

    session.run();
}
