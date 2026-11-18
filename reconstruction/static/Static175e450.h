// Source exposure: binary-analysis; no external implementation source reused.
// Static175e450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e450*);
    virtual void release(Static175e450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e450*);
struct Static175e450 {
    void* value;
    Static175e450();
    ~Static175e450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
