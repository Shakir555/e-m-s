#ifndef GRADIENTSTYLE_H
#define GRADIENTSTYLE_H

#include <QString>
#include <array>

class GradientStyle
{
public:
    static constexpr std::array<int, 3> RGB_WHITE = {255, 255, 255};
    static constexpr std::array<int, 3> RGB_GOLD_COLOR = {255, 215, 0};  // Renamed to avoid conflict

    enum GradientType {
        TYPE_GOLD  // Renamed from RGB_GOLD
    };

    static QString specifyGradientStyle(GradientType type) {
        switch (type) {
        case TYPE_GOLD:
            return QStringLiteral("qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                                  "stop:0 rgb(255, 223, 0), stop:1 rgb(255, 185, 15))");
        default:
            return QStringLiteral("rgb(255, 255, 255)");
        }
    }
};

#endif // GRADIENTSTYLE_H
