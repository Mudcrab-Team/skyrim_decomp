// Source exposure: binary-analysis; no external implementation source reused.
// Static1773030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773030*);
    virtual void release(Static1773030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773030*);
struct Static1773030 {
    void* value;
    Static1773030();
    ~Static1773030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
