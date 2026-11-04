#include "PluginEditor.h"

namespace
{
    // Цвета и названия шести модулей
}

// Конструктор редактора
ENGINEGURAudioProcessorEditor::ENGINEGURAudioProcessorEditor(...)
{
    // Инициализация интерфейса
}

// Рисование интерфейса
void ENGINEGURAudioProcessorEditor::paint(juce::Graphics& g)
{
    // Фон и верхняя панель

    const int margin = 18;
    const int gap = 12;
    const int top = 122;
    const int w = (getWidth() - 2 * margin - 2 * gap) / 3;
    const int h = 270;

    for (int i = 0; i < 6; ++i)
    {
        int x = margin + (i % 3) * (w + gap);
        int y = top + (i / 3) * (h + gap);

        juce::Rectangle<float> r{
            float(x), float(y), float(w), float(h)
        };

        g.setColour(dark);
        g.fillRoundedRectangle(r, 12);

        g.setColour(juce::Colour(0xff2b374b));
        g.drawRoundedRectangle(r, 12, 1);

        // Остальная отрисовка модулей
    }

    // Нижние подписи
}

// Изменение размеров
void ENGINEGURAudioProcessorEditor::resized()
{
    // Расположение элементов
}

// Обработка кнопок
void ENGINEGURAudioProcessorEditor::buttonClicked(juce::Button* b)
{
    // LOAD / GENERATE / EXPORT
}
