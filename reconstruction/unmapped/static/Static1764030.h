// Source exposure: binary-analysis; no external implementation source reused.
// Static1764030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764030*);
    virtual void release(Static1764030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764030*);
struct Static1764030 {
    void* value;
    Static1764030();
    ~Static1764030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
