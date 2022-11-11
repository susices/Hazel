#include "hzpch.h"
#include "LayerStack.h"

namespace Hazel
{
    LayerStack::LayerStack()
    {
        m_LayerInsert = m_Layers.begin();
    }

    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_Layers)
            delete layer;
    }

    void LayerStack::PushLayer(Layer* layer)
    {
        m_LayerInsert = m_Layers.emplace(m_LayerInsert,layer);
    }

    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_Layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer* layer)
    {
        auto iter = std::find(m_Layers.begin(), m_Layers.end(),layer);
        if (iter != m_Layers.end())
        {
            m_Layers.erase(iter);
            m_LayerInsert--;
        }
    }

    void LayerStack::PopOverlay(Layer* overlay)
    {
        auto iter = std::find(m_Layers.begin(), m_Layers.end(),overlay);
        if (iter!=m_Layers.end())
        {
            m_Layers.erase(iter);
        }
    }
}
