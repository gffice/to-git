/* subproto_request.c -- generated by Trunnel v1.5.3.
 * https://gitweb.torproject.org/trunnel.git
 * You probably shouldn't edit this file.
 */
#include <stdlib.h>
#include "trunnel-impl.h"

#include "subproto_request.h"

#define TRUNNEL_SET_ERROR_CODE(obj) \
  do {                              \
    (obj)->trunnel_error_code_ = 1; \
  } while (0)

#if defined(__COVERITY__) || defined(__clang_analyzer__)
/* If we're running a static analysis tool, we don't want it to complain
 * that some of our remaining-bytes checks are dead-code. */
int subprotorequest_deadcode_dummy__ = 0;
#define OR_DEADCODE_DUMMY || subprotorequest_deadcode_dummy__
#else
#define OR_DEADCODE_DUMMY
#endif

#define CHECK_REMAINING(nbytes, label)                           \
  do {                                                           \
    if (remaining < (nbytes) OR_DEADCODE_DUMMY) {                \
      goto label;                                                \
    }                                                            \
  } while (0)

trn_subproto_request_t *
trn_subproto_request_new(void)
{
  trn_subproto_request_t *val = trunnel_calloc(1, sizeof(trn_subproto_request_t));
  if (NULL == val)
    return NULL;
  return val;
}

/** Release all storage held inside 'obj', but do not free 'obj'.
 */
static void
trn_subproto_request_clear(trn_subproto_request_t *obj)
{
  (void) obj;
}

void
trn_subproto_request_free(trn_subproto_request_t *obj)
{
  if (obj == NULL)
    return;
  trn_subproto_request_clear(obj);
  trunnel_memwipe(obj, sizeof(trn_subproto_request_t));
  trunnel_free_(obj);
}

uint8_t
trn_subproto_request_get_protocol_id(const trn_subproto_request_t *inp)
{
  return inp->protocol_id;
}
int
trn_subproto_request_set_protocol_id(trn_subproto_request_t *inp, uint8_t val)
{
  inp->protocol_id = val;
  return 0;
}
uint8_t
trn_subproto_request_get_proto_cap_number(const trn_subproto_request_t *inp)
{
  return inp->proto_cap_number;
}
int
trn_subproto_request_set_proto_cap_number(trn_subproto_request_t *inp, uint8_t val)
{
  inp->proto_cap_number = val;
  return 0;
}
const char *
trn_subproto_request_check(const trn_subproto_request_t *obj)
{
  if (obj == NULL)
    return "Object was NULL";
  if (obj->trunnel_error_code_)
    return "A set function failed on this object";
  return NULL;
}

ssize_t
trn_subproto_request_encoded_len(const trn_subproto_request_t *obj)
{
  ssize_t result = 0;

  if (NULL != trn_subproto_request_check(obj))
     return -1;


  /* Length of u8 protocol_id */
  result += 1;

  /* Length of u8 proto_cap_number */
  result += 1;
  return result;
}
int
trn_subproto_request_clear_errors(trn_subproto_request_t *obj)
{
  int r = obj->trunnel_error_code_;
  obj->trunnel_error_code_ = 0;
  return r;
}
ssize_t
trn_subproto_request_encode(uint8_t *output, const size_t avail, const trn_subproto_request_t *obj)
{
  ssize_t result = 0;
  size_t written = 0;
  uint8_t *ptr = output;
  const char *msg;
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  const ssize_t encoded_len = trn_subproto_request_encoded_len(obj);
#endif

  if (NULL != (msg = trn_subproto_request_check(obj)))
    goto check_failed;

#ifdef TRUNNEL_CHECK_ENCODED_LEN
  trunnel_assert(encoded_len >= 0);
#endif

  /* Encode u8 protocol_id */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->protocol_id));
  written += 1; ptr += 1;

  /* Encode u8 proto_cap_number */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->proto_cap_number));
  written += 1; ptr += 1;


  trunnel_assert(ptr == output + written);
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  {
    trunnel_assert(encoded_len >= 0);
    trunnel_assert((size_t)encoded_len == written);
  }

#endif

  return written;

 truncated:
  result = -2;
  goto fail;
 check_failed:
  (void)msg;
  result = -1;
  goto fail;
 fail:
  trunnel_assert(result < 0);
  return result;
}

/** As trn_subproto_request_parse(), but do not allocate the output
 * object.
 */
static ssize_t
trn_subproto_request_parse_into(trn_subproto_request_t *obj, const uint8_t *input, const size_t len_in)
{
  const uint8_t *ptr = input;
  size_t remaining = len_in;
  ssize_t result = 0;
  (void)result;

  /* Parse u8 protocol_id */
  CHECK_REMAINING(1, truncated);
  obj->protocol_id = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;

  /* Parse u8 proto_cap_number */
  CHECK_REMAINING(1, truncated);
  obj->proto_cap_number = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;
  trunnel_assert(ptr + remaining == input + len_in);
  return len_in - remaining;

 truncated:
  return -2;
}

ssize_t
trn_subproto_request_parse(trn_subproto_request_t **output, const uint8_t *input, const size_t len_in)
{
  ssize_t result;
  *output = trn_subproto_request_new();
  if (NULL == *output)
    return -1;
  result = trn_subproto_request_parse_into(*output, input, len_in);
  if (result < 0) {
    trn_subproto_request_free(*output);
    *output = NULL;
  }
  return result;
}
trn_subproto_request_ext_t *
trn_subproto_request_ext_new(void)
{
  trn_subproto_request_ext_t *val = trunnel_calloc(1, sizeof(trn_subproto_request_ext_t));
  if (NULL == val)
    return NULL;
  return val;
}

/** Release all storage held inside 'obj', but do not free 'obj'.
 */
static void
trn_subproto_request_ext_clear(trn_subproto_request_ext_t *obj)
{
  (void) obj;
  {

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->reqs); ++idx) {
      trn_subproto_request_free(TRUNNEL_DYNARRAY_GET(&obj->reqs, idx));
    }
  }
  TRUNNEL_DYNARRAY_WIPE(&obj->reqs);
  TRUNNEL_DYNARRAY_CLEAR(&obj->reqs);
}

void
trn_subproto_request_ext_free(trn_subproto_request_ext_t *obj)
{
  if (obj == NULL)
    return;
  trn_subproto_request_ext_clear(obj);
  trunnel_memwipe(obj, sizeof(trn_subproto_request_ext_t));
  trunnel_free_(obj);
}

size_t
trn_subproto_request_ext_getlen_reqs(const trn_subproto_request_ext_t *inp)
{
  return TRUNNEL_DYNARRAY_LEN(&inp->reqs);
}

struct trn_subproto_request_st *
trn_subproto_request_ext_get_reqs(trn_subproto_request_ext_t *inp, size_t idx)
{
  return TRUNNEL_DYNARRAY_GET(&inp->reqs, idx);
}

 const struct trn_subproto_request_st *
trn_subproto_request_ext_getconst_reqs(const trn_subproto_request_ext_t *inp, size_t idx)
{
  return trn_subproto_request_ext_get_reqs((trn_subproto_request_ext_t*)inp, idx);
}
int
trn_subproto_request_ext_set_reqs(trn_subproto_request_ext_t *inp, size_t idx, struct trn_subproto_request_st * elt)
{
  trn_subproto_request_t *oldval = TRUNNEL_DYNARRAY_GET(&inp->reqs, idx);
  if (oldval && oldval != elt)
    trn_subproto_request_free(oldval);
  return trn_subproto_request_ext_set0_reqs(inp, idx, elt);
}
int
trn_subproto_request_ext_set0_reqs(trn_subproto_request_ext_t *inp, size_t idx, struct trn_subproto_request_st * elt)
{
  TRUNNEL_DYNARRAY_SET(&inp->reqs, idx, elt);
  return 0;
}
int
trn_subproto_request_ext_add_reqs(trn_subproto_request_ext_t *inp, struct trn_subproto_request_st * elt)
{
  TRUNNEL_DYNARRAY_ADD(struct trn_subproto_request_st *, &inp->reqs, elt, {});
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}

struct trn_subproto_request_st * *
trn_subproto_request_ext_getarray_reqs(trn_subproto_request_ext_t *inp)
{
  return inp->reqs.elts_;
}
const struct trn_subproto_request_st *  const  *
trn_subproto_request_ext_getconstarray_reqs(const trn_subproto_request_ext_t *inp)
{
  return (const struct trn_subproto_request_st *  const  *)trn_subproto_request_ext_getarray_reqs((trn_subproto_request_ext_t*)inp);
}
int
trn_subproto_request_ext_setlen_reqs(trn_subproto_request_ext_t *inp, size_t newlen)
{
  struct trn_subproto_request_st * *newptr;
  newptr = trunnel_dynarray_setlen(&inp->reqs.allocated_,
                 &inp->reqs.n_, inp->reqs.elts_, newlen,
                 sizeof(inp->reqs.elts_[0]), (trunnel_free_fn_t) trn_subproto_request_free,
                 &inp->trunnel_error_code_);
  if (newlen != 0 && newptr == NULL)
    goto trunnel_alloc_failed;
  inp->reqs.elts_ = newptr;
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}
const char *
trn_subproto_request_ext_check(const trn_subproto_request_ext_t *obj)
{
  if (obj == NULL)
    return "Object was NULL";
  if (obj->trunnel_error_code_)
    return "A set function failed on this object";
  {
    const char *msg;

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->reqs); ++idx) {
      if (NULL != (msg = trn_subproto_request_check(TRUNNEL_DYNARRAY_GET(&obj->reqs, idx))))
        return msg;
    }
  }
  return NULL;
}

ssize_t
trn_subproto_request_ext_encoded_len(const trn_subproto_request_ext_t *obj)
{
  ssize_t result = 0;

  if (NULL != trn_subproto_request_ext_check(obj))
     return -1;


  /* Length of struct trn_subproto_request reqs[] */
  {

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->reqs); ++idx) {
      result += trn_subproto_request_encoded_len(TRUNNEL_DYNARRAY_GET(&obj->reqs, idx));
    }
  }
  return result;
}
int
trn_subproto_request_ext_clear_errors(trn_subproto_request_ext_t *obj)
{
  int r = obj->trunnel_error_code_;
  obj->trunnel_error_code_ = 0;
  return r;
}
ssize_t
trn_subproto_request_ext_encode(uint8_t *output, const size_t avail, const trn_subproto_request_ext_t *obj)
{
  ssize_t result = 0;
  size_t written = 0;
  uint8_t *ptr = output;
  const char *msg;
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  const ssize_t encoded_len = trn_subproto_request_ext_encoded_len(obj);
#endif

  if (NULL != (msg = trn_subproto_request_ext_check(obj)))
    goto check_failed;

#ifdef TRUNNEL_CHECK_ENCODED_LEN
  trunnel_assert(encoded_len >= 0);
#endif

  /* Encode struct trn_subproto_request reqs[] */
  {

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->reqs); ++idx) {
      trunnel_assert(written <= avail);
      result = trn_subproto_request_encode(ptr, avail - written, TRUNNEL_DYNARRAY_GET(&obj->reqs, idx));
      if (result < 0)
        goto fail; /* XXXXXXX !*/
      written += result; ptr += result;
    }
  }


  trunnel_assert(ptr == output + written);
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  {
    trunnel_assert(encoded_len >= 0);
    trunnel_assert((size_t)encoded_len == written);
  }

#endif

  return written;

 check_failed:
  (void)msg;
  result = -1;
  goto fail;
 fail:
  trunnel_assert(result < 0);
  return result;
}

/** As trn_subproto_request_ext_parse(), but do not allocate the
 * output object.
 */
static ssize_t
trn_subproto_request_ext_parse_into(trn_subproto_request_ext_t *obj, const uint8_t *input, const size_t len_in)
{
  const uint8_t *ptr = input;
  size_t remaining = len_in;
  ssize_t result = 0;
  (void)result;

  /* Parse struct trn_subproto_request reqs[] */
  {
    trn_subproto_request_t * elt;
    while (remaining > 0) {
      result = trn_subproto_request_parse(&elt, ptr, remaining);
      if (result < 0)
        goto fail;
      trunnel_assert((size_t)result <= remaining);
      remaining -= result; ptr += result;
      TRUNNEL_DYNARRAY_ADD(trn_subproto_request_t *, &obj->reqs, elt, {trn_subproto_request_free(elt);});
    }
  }
  trunnel_assert(ptr + remaining == input + len_in);
  return len_in - remaining;

 trunnel_alloc_failed:
  return -1;
 fail:
  result = -1;
  return result;
}

ssize_t
trn_subproto_request_ext_parse(trn_subproto_request_ext_t **output, const uint8_t *input, const size_t len_in)
{
  ssize_t result;
  *output = trn_subproto_request_ext_new();
  if (NULL == *output)
    return -1;
  result = trn_subproto_request_ext_parse_into(*output, input, len_in);
  if (result < 0) {
    trn_subproto_request_ext_free(*output);
    *output = NULL;
  }
  return result;
}
