﻿#pragma once
#define NO_S3D_USING
#include <Siv3D.hpp>

namespace SivSUSAnalyzer {
    struct Note {
        s3d::int32 channel;
        s3d::int32 lane;
        s3d::int32 laneType;
        s3d::int32 measure;
        s3d::int32 noteType;
        s3d::int32 tick;
        s3d::int32 width;
    };

    struct Score {
        s3d::int32 measure;
        s3d::Array<double> bpmList;
        s3d::Array<Note> tapNotes;
        s3d::Array<Note> holdNotes;
    };

    Score ParseScore(const s3d::String& data);
}
