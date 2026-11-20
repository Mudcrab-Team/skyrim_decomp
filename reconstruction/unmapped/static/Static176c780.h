// Source exposure: binary-analysis; no external implementation source reused.
// Static176c780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c780*);
    virtual void release(Static176c780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c780*);
struct Static176c780 {
    void* value;
    Static176c780();
    ~Static176c780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
