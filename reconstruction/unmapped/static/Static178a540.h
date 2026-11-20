// Source exposure: binary-analysis; no external implementation source reused.
// Static178a540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a540*);
    virtual void release(Static178a540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a540*);
struct Static178a540 {
    void* value;
    Static178a540();
    ~Static178a540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
