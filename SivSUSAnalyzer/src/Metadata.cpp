#include "SivSUSAnalyzer/Metadata.hpp"

namespace SivSUSAnalyzer {
    namespace {
        s3d::String ParseRawString(const s3d::String& raw) {
            if (raw.starts_with('\"') and raw.ends_with('\"')) {
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
        } else if (key == U"DESINGER") {
            designer = ParseRawString(value);
        } else if (key == U"DIFFICULTY") {
        } else if (key == U"PLAYLEVEL") {
        } else if (key == U"SONGID") {
        } else if (key == U"WAVE") {
        } else if (key == U"WAVEOFFSET") {
        } else if (key == U"JACKET") {
        } else if (key == U"BACKGROUND") {
        } else if (key == U"MOVIE") {
        } else if (key == U"MOVIEOFFSET") {
        } else if (key == U"BASEBPM") {
        } else if (key == U"REQUEST") {
        } else {
            return false;
        }
    }

    Metadata ParseMetadata(const s3d::String& data) {
        Metadata result;
        for (const auto lines = data.split_lines(); const auto & line : lines) {
            if (line.starts_with('#')) {

            }
        }
        return result;
    }
}
