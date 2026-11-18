// Source exposure: binary-analysis; no external implementation source reused.
// Static1764260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764260*);
    virtual void release(Static1764260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764260*);
struct Static1764260 {
    void* value;
    Static1764260();
    ~Static1764260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
