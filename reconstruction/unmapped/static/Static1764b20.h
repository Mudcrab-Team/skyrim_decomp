// Source exposure: binary-analysis; no external implementation source reused.
// Static1764b20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764b20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764b20*);
    virtual void release(Static1764b20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764b20*);
struct Static1764b20 {
    void* value;
    Static1764b20();
    ~Static1764b20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
