# yae-dcc-plugins

[English](README.md) · [Русский](README.ru.md)

Plugins from 2013 that bring *You Are Empty* models into two DCC (digital content creation)
packages: a `.ds2md` **importer for Autodesk 3ds Max** (2008–2012 SDKs) and a **model translator
for Autodesk Maya**, sharing a small C++ core (`yae_core`: file system, math, mesh, DS2 reader).

Part of [Project Empty](https://github.com/OpenYAE), the open ecosystem around the 2006 game.

## Status: unmaintained, looking for a maintainer

- The Visual Studio 2008 projects (`.vcproj`) and the Max 2008–2012 / Maya SDK paths are as they
  were left in 2013; nothing here has been built against a current 3ds Max or Maya.
- The supported path for models today is the [YAE SDK](https://github.com/OpenYAE/yae-sdk):
  `.ds2md` → glTF/GLB with skeleton, skin weights and animations, which 3ds Max, Maya and
  Blender all import natively, and glTF → `.ds2md` back.
- The repository stays public as a reference for the format (the reader in `yae_core` is
  independent of any DCC package) and for anyone who wants to revive a native plugin. If that is
  you, open an issue: the maintainers will hand over write access.

## Layout

```
yae-tools.sln            Visual Studio 2008 solution
yae_core/                DS2MD reader, mesh and math helpers shared by both plugins
yae_plugin_3dsmax/       3ds Max importer (model_import.cpp, plugin.def)
yae_plugin_maya/         Maya file translator (yae_model_translator.cpp)
```

## Building (historical)

1. Install the 3ds Max SDK of the version you target and set `MAXSDK` (the project files carry
   configurations for 3ds Max 2008 through 2012), or the Maya devkit for the Maya plugin.
2. Open `yae-tools.sln` in Visual Studio 2008 (or upgrade the projects) and build the plugin for
   the DCC package's platform.
3. Copy the resulting `.dli`/`.mll` into the package's plugin directory.

## Legal

*You Are Empty* and its formats belong to their rights holders; this repository contains no game
assets. The plugins are under the WTFPL, version 2, as their original authors released
them ([LICENSE](LICENSE), [NOTICE](NOTICE)).
