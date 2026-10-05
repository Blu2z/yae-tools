# yae-dcc-plugins

[English](README.md) · [Русский](README.ru.md)

Плагины 2013 года, которые импортируют модели *You Are Empty* в два DCC-пакета (digital content
creation): **импортёр `.ds2md` для Autodesk 3ds Max** (SDK 2008–2012) и **транслятор моделей для
Autodesk Maya** с общим ядром на C++ (`yae_core`: файловая система, математика, меш, чтение DS2).

Часть [Project Empty](https://github.com/OpenYAE), открытой экосистемы вокруг игры 2006 года.

## Статус: не поддерживается, ищем сопровождающего

- Проекты Visual Studio 2008 (`.vcproj`) и пути к SDK 3ds Max 2008–2012 / Maya остались как в
  2013 году; под современные версии пакетов ничего не собиралось.
- Поддерживаемый сегодня путь для моделей — [YAE SDK](https://github.com/OpenYAE/yae-sdk):
  `.ds2md` → glTF/GLB со скелетом, весами и анимациями, которые 3ds Max, Maya и Blender
  импортируют штатно, и glTF → `.ds2md` обратно.
- Репозиторий остаётся публичным как справка по формату (читатель в `yae_core` не зависит от
  DCC-пакета) и для того, кто захочет оживить нативный плагин. Если это вы — откройте issue.

## Раскладка

```
yae-tools.sln            решение Visual Studio 2008
yae_core/                читатель DS2MD, меш и математика, общие для обоих плагинов
yae_plugin_3dsmax/       импортёр 3ds Max (model_import.cpp, plugin.def)
yae_plugin_maya/         file translator для Maya (yae_model_translator.cpp)
```

Сборка описана в английской версии. Плагины распространяются под WTFPL версии 2, как их выпустили
исходные авторы ([LICENSE](LICENSE), [NOTICE](NOTICE)); игровые ресурсы в репозитории отсутствуют.
