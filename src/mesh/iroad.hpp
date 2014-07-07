#ifndef IROAD_HPP
#define IROAD_HPP

#include "spline/ispline.hpp"
#include "mesh/mesh_structs.hpp"

class IRoad :public ISceneNode
{
protected:
    ISpline*        m_spline;
    Mesh            m_mesh;

    float           m_detail;
    float           m_width;
    int             m_width_vert_num;

    SMaterial       m_material;

    aabbox3d<f32>   m_bounding_box;

public:
    IRoad(ISceneNode* parent, ISceneManager* mgr, s32 id, ISpline* s, stringw n);

    virtual void    refresh() = 0;

    void            setDetail(float d)      { m_detail = d; refresh(); }
    void            setWidth(float d)       { m_width =  d; refresh(); }

    ISpline*        getSpline()             { return m_spline; }

// ----------------------------------------------------------------------------
    // inherited functions - ISceneNode
    void                 OnRegisterSceneNode();
    virtual void         render() = 0;

    const aabbox3d<f32>& getBoundingBox()   const { return m_bounding_box; }
    u32                  getMaterialCount() const { return 1; }

};

#endif
