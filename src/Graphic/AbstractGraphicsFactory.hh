#ifndef DE_RINTO_ENGINE_GRAPHIC_ABSTRACTGRAPHICSFACTORY_HH_INCLUDED
#define DE_RINTO_ENGINE_GRAPHIC_ABSTRACTGRAPHICSFACTORY_HH_INCLUDED

namespace de::rinto::Engine::Graphic {
    class AbstractGraphicsFactory {
    public:
        void get(std::string uuid);
    };
} // namespace de::rinto::Engine::Graphic

#endif // DE_RINTO_ENGINE_GRAPHIC_ABSTRACTGRAPHICSFACTORY_HH_INCLUDED