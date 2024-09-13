#include "SivSUSAnalyzer/Metadata.hpp"

namespace SivSUSAnalyzer {
    namespace {
        s3d::String ParseRawString(const s3d::String& raw) {
            if (raw.starts_with('\"') and raw.ends_with('\"')) {
                // TODO: process escaping
                const auto length = raw.size();
                return raw.substr(1, length - 2);
            } else {
                return raw; // invalid;
            }
        }
    }

    MetadataEntry::MetadataEntry(const s3d::String& line) {
        if (!line.starts_with('#')) {
            return; // invalid
        }
        const auto spacePosition = line.indexOf(' ');
        if (spacePosition == s3d::String::npos) {
            return; // invalid
        }   
        value = line.substr(spacePosition + 1).trim();
        key = line.take(spacePosition).substr(1).trim().uppercased();
    }

    bool Metadata::parseMetadataEntry(const MetadataEntry& entry) {
        const auto& [key, value] = entry;

        if (key == U"TITLE") {
            title = ParseRawString(value);
        } else if (key == U"SUBTITLE") {
            subtitle = ParseRawString(value);
        } else if (key == U"ARTIST") {
            artist = ParseRawString(value);
        } else if (key == U"GENRE") {
            genre = ParseRawString(value);
        } else if (key == U"DESIGNER") {
            designer = ParseRawString(value);
        } else if (key == U"DIFFICULTY") {
            if (value.all([](const auto c) { return s3d::IsDigit(c); })) {
                difficulty = value;
            } else {
                difficulty = ParseRawString(value);
            }
        } else if (key == U"PLAYLEVEL") {
            playLevel = ParseRawString(value);
        } else if (key == U"SONGID") {
            songID = ParseRawString(value);
        } else if (key == U"WAVE") {
            wave = ParseRawString(value);
        } else if (key == U"WAVEOFFSET") {
            // TODO: error handling
            waveOffset = s3d::ParseOr<double>(value, 0.0);
        } else if (key == U"JACKET") {
            jacket = ParseRawString(value);
        } else if (key == U"BACKGROUND") {
            background = ParseRawString(value);
        } else if (key == U"MOVIE") {
            movie = ParseRawString(value);
        } else if (key == U"MOVIEOFFSET") {
            movieOffset = s3d::ParseOr<double>(value, 0.0);
        } else if (key == U"BASEBPM") {
            baseBPM = s3d::ParseOr<double>(value, 120.0);
        } else if (key == U"REQUEST") {
            requests.push_back(value);
        } else {
            return false;
        }
    }

    Metadata ParseMetadata(const s3d::String& data) {
        Metadata result;
        for (const auto lines = data.split_lines(); const auto & line : lines) {
            if (line.starts_with('#') and line.size() >= 4) {
                if (s3d::IsDigit(line[1]) and s3d::IsDigit(line[2]) and s3d::IsDigit(line[3])) {
                    continue; // score data
                }
                result.parseMetadataEntry(MetadataEntry(line));
            }
        }
        return result;
    }
}
