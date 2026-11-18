// Source exposure: binary-analysis; no external implementation source reused.
// Static1792390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1792390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1792390*);
    virtual void release(Static1792390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1792390*);
struct Static1792390 {
    void* value;
    Static1792390();
    ~Static1792390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
