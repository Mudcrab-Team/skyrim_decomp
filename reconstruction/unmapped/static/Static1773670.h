// Source exposure: binary-analysis; no external implementation source reused.
// Static1773670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773670*);
    virtual void release(Static1773670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773670*);
struct Static1773670 {
    void* value;
    Static1773670();
    ~Static1773670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
