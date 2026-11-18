// Source exposure: binary-analysis; no external implementation source reused.
// Static1782490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782490*);
    virtual void release(Static1782490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782490*);
struct Static1782490 {
    void* value;
    Static1782490();
    ~Static1782490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
