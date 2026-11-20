// Source exposure: binary-analysis; no external implementation source reused.
// Static1764080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764080*);
    virtual void release(Static1764080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764080*);
struct Static1764080 {
    void* value;
    Static1764080();
    ~Static1764080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
