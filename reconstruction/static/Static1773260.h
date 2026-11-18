// Source exposure: binary-analysis; no external implementation source reused.
// Static1773260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773260*);
    virtual void release(Static1773260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773260*);
struct Static1773260 {
    void* value;
    Static1773260();
    ~Static1773260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
