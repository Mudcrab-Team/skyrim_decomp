// Source exposure: binary-analysis; no external implementation source reused.
// Static175fa30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fa30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fa30*);
    virtual void release(Static175fa30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fa30*);
struct Static175fa30 {
    void* value;
    Static175fa30();
    ~Static175fa30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
